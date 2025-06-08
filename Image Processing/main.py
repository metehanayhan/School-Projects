# METEHAN AYHAN

import cv2 
from deepface import DeepFace  # Yüz tanıma ve duygu analizi için DeepFace kütüphanesi
from datetime import datetime  # Zaman damgası oluşturmak için
import threading  # Eşzamanlı işlem yapmak için (kamera ve analiz aynı anda)
import time  
import tkinter as tk  # GUI (grafik arayüz) oluşturmak için
from tkinter import Label  # Tkinter içinden etiket aracı
from PIL import Image, ImageTk  # OpenCV görüntüsünü GUI'ye uyarlamak için
import pandas as pd 
import os  

# ---------------- EMOJİLERİ YÖNETEN SINIF ----------------
class EmojiManager:
    def __init__(self):
        # Duygulara karşılık gelen emoji resimlerini yüklüyoruz
        self.emojis = {
            "angry": self.load_emoji("emojipng/kizgin.png"),
            "disgust": self.load_emoji("emojipng/igrenme.png"),
            "fear": self.load_emoji("emojipng/korkmus.png"),
            "happy": self.load_emoji("emojipng/mutlu.png"),
            "sad": self.load_emoji("emojipng/uzgun.png"),
            "surprise": self.load_emoji("emojipng/saskin.png"),
            "neutral": self.load_emoji("emojipng/ifadesiz.png")
        }

    def load_emoji(self, path):
        # Belirtilen yol üzerinden emoji resmini yükler
        img = cv2.imread(path)
        if img is None:
            raise FileNotFoundError(f"Emoji dosyası bulunamadı: {path}")
        return img

    def get_emoji(self, emotion):
        # İlgili duyguya karşılık gelen emojiyi döndürür
        return self.emojis.get(emotion)

# ---------------- DUYGU KAYDI SINIFI ----------------
class EmotionLogger:
    def __init__(self, filename="duygu_kaydi.csv"):
        # Dosya adı belirleniyor, dosya yoksa başlık satırı ile oluşturuluyor
        self.filename = filename
        self.initialize_file()

    def initialize_file(self):
        # Dosya yoksa oluştur ve başlık satırını yaz
        if not os.path.exists(self.filename):
            with open(self.filename, "w") as f:
                f.write("timestamp,emotion\n")

    def log_emotion(self, emotion):
        # Şu anki zamanı ve tespit edilen duyguyu dosyaya kaydeder
        timestamp = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
        with open(self.filename, "a") as f:
            f.write(f"{timestamp},{emotion}\n")

# ---------------- KAMERA ve ANALİZ SINIFI ----------------
class RuhHaliTakip:
    def __init__(self, label_video, label_duygu, label_emoji):
        # Kamerayı başlat
        self.cap = cv2.VideoCapture(0)
        if not self.cap.isOpened():
            raise RuntimeError("Kamera açılamadı")
        
        # GUI bileşenleri atanıyor
        self.label_video = label_video
        self.label_duygu = label_duygu
        self.label_emoji = label_emoji
        self.running = False  # Başlangıçta çalışmıyor
        self.emoji_manager = EmojiManager()  # Emoji yöneticisi
        self.logger = EmotionLogger()  # Duygu kayıt sistemi

    def start(self):
        # Takip başlatılıyor, iki ayrı thread çalışıyor
        self.running = True
        threading.Thread(target=self.update, daemon=True).start()
        threading.Thread(target=self.analyze_emotion, daemon=True).start()

    def stop(self):
        # Takip durduruluyor, kamera serbest bırakılıyor
        self.running = False
        self.cap.release()

    def update(self):
        # Kamera görüntüsünü GUI'ye sürekli aktarır
        while self.running:
            ret, frame = self.cap.read()
            if not ret:
                continue
            rgb = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
            img = Image.fromarray(rgb)
            imgtk = ImageTk.PhotoImage(image=img)
            self.label_video.imgtk = imgtk
            self.label_video.configure(image=imgtk)

    def analyze_emotion(self):
        # Her saniyede bir yüz ifadesini analiz eder
        while self.running:
            ret, frame = self.cap.read()
            if not ret:
                continue
            try:
                # DeepFace ile duygu analizi
                result = DeepFace.analyze(frame, actions=['emotion'], enforce_detection=False)
                emotion = result[0]['dominant_emotion']
                self.logger.log_emotion(emotion)  # Kaydet
                self.update_gui(emotion)  # GUI'yi güncelle
            except Exception as e:
                print(f"Hata: {str(e)}")
            time.sleep(1)  # 1 saniyede bir analiz

    def update_gui(self, emotion):
        # GUI'de duygu metnini ve emojiyi günceller
        self.label_duygu.config(text=f"Anlık Duygu: {emotion.upper()}")

        emoji = self.emoji_manager.get_emoji(emotion)
        if emoji is not None:
            emoji_resized = cv2.resize(emoji, (100, 100))
            emoji_rgb = cv2.cvtColor(emoji_resized, cv2.COLOR_BGR2RGB)
            emoji_img = Image.fromarray(emoji_rgb)
            emoji_tk = ImageTk.PhotoImage(image=emoji_img)
            self.label_emoji.imgtk = emoji_tk
            self.label_emoji.configure(image=emoji_tk)

# ---------------- ARAYÜZ SINIFI ----------------
class EmotionTrackerApp:
    def __init__(self):
        self.root = tk.Tk()
        self.root.title("Ruh Hali Takipçisi")
        self.configure_window()
        self.setup_ui()
        self.tracker = None

    def configure_window(self):
        # Pencere ortalanarak belirli bir boyutta başlatılır
        window_width = 800
        window_height = 600
        screen_width = self.root.winfo_screenwidth()
        screen_height = self.root.winfo_screenheight()
        x = int((screen_width/2) - (window_width/2))
        y = int((screen_height/2) - (window_height/2))
        self.root.geometry(f"{window_width}x{window_height}+{x}+{y}")
        self.root.minsize(600, 400)
        self.root.configure(bg="#f0f0f0")

    def setup_ui(self):
        # Arayüzdeki çerçeveler ve bileşenler oluşturuluyor
        main_frame = tk.Frame(self.root, bg="#f0f0f0")
        main_frame.pack(fill=tk.BOTH, expand=True, padx=20, pady=20)

        video_frame = tk.Frame(main_frame, bg="white", relief=tk.RAISED, bd=2)
        video_frame.pack(fill=tk.BOTH, expand=True, pady=(0, 20))
        
        self.video_label = Label(video_frame, bg="black")
        self.video_label.pack(fill=tk.BOTH, expand=True, padx=10, pady=10)

        footer_frame = tk.Frame(main_frame, bg="#f0f0f0")
        footer_frame.pack(fill=tk.X)

        self.emotion_label = Label(footer_frame, 
                                   text="Anlık Duygu: -", 
                                   font=("Arial", 14, "bold"),
                                   fg="#333333",
                                   bg="#f0f0f0")
        self.emotion_label.pack(side=tk.LEFT, padx=(0, 20))

        self.emoji_label = Label(footer_frame, bg="#f0f0f0")
        self.emoji_label.pack(side=tk.LEFT)

        button_frame = tk.Frame(main_frame, bg="#f0f0f0")
        button_frame.pack(fill=tk.X, pady=(10, 0))

        # Başlat ve durdur butonları
        self.start_button = tk.Button(button_frame, text="Başlat", command=self.start_tracking,
                                      bg="#4CAF50", fg="white", font=("Arial", 12), padx=20, pady=10, relief=tk.FLAT)
        self.start_button.pack(side=tk.LEFT, padx=(0, 10))

        self.stop_button = tk.Button(button_frame, text="Durdur", command=self.stop_tracking,
                                     bg="#F44336", fg="white", font=("Arial", 12), padx=20, pady=10, relief=tk.FLAT)
        self.stop_button.pack(side=tk.LEFT)

    def start_tracking(self):
        # İzleme işlemini başlatır
        self.tracker = RuhHaliTakip(self.video_label, self.emotion_label, self.emoji_label)
        self.tracker.start()

    def stop_tracking(self):
        # İzlemeyi durdurur ve pencereyi kapatır
        if self.tracker:
            self.tracker.stop()
        self.root.destroy()

    def run(self):
        # Arayüzü çalıştır
        self.root.mainloop()

# ---------------- ANA PROGRAM ----------------
if __name__ == "__main__":
    app = EmotionTrackerApp()
    app.run()
