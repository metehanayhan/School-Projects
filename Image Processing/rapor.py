import pandas as pd
import matplotlib.pyplot as plt

def goster_gunluk_rapor():
    try:
        df = pd.read_csv("duygu_kaydi.csv", parse_dates=["timestamp"])
    except Exception as e:
        print("CSV okunamadı:", e)
        return

    df["saat"] = df["timestamp"].dt.strftime("%H:%M")

    plt.figure(figsize=(10, 5))
    plt.plot(df["saat"], df["emotion"], marker="o")
    plt.title("Günlük Ruh Hali Değişimi")
    plt.xlabel("Saat")
    plt.ylabel("Duygu")
    plt.xticks(rotation=45)
    plt.tight_layout()
    plt.show()

if __name__ == "__main__":
    goster_gunluk_rapor()
