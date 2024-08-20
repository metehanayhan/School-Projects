#METEHAN AYHAN

class Node:
    def __init__(self, data, color="R"):
        self.data = data
        self.color = color
        self.left = None
        self.right = None
        self.parent = None

class RedBlackTree:
    def __init__(self):
        self.NIL_LEAF = Node(data=None, color="B")
        self.root = self.NIL_LEAF

    def insert(self, data):
        new_node = Node(data)
        new_node.left = self.NIL_LEAF
        new_node.right = self.NIL_LEAF
        if self.root == self.NIL_LEAF:
            self.root = new_node
            self.root.color = "B"
            self.root.parent = None
        else:
            self._insert_helper(self.root, new_node)
            self.fix_insert(new_node)

    def _insert_helper(self, current, new_node):
        if new_node.data < current.data:
            if current.left == self.NIL_LEAF:
                current.left = new_node
                new_node.parent = current
            else:
                self._insert_helper(current.left, new_node)
        else:
            if current.right == self.NIL_LEAF:
                current.right = new_node
                new_node.parent = current
            else:
                self._insert_helper(current.right, new_node)

    def fix_insert(self, node):
        while node != self.root and node.parent.color == "R":
            if node.parent == node.parent.parent.left:
                uncle = node.parent.parent.right
                if uncle.color == "R":
                    node.parent.color = "B"
                    uncle.color = "B"
                    node.parent.parent.color = "R"
                    node = node.parent.parent
                else:
                    if node == node.parent.right:
                        node = node.parent
                        self.left_rotate(node)
                    node.parent.color = "B"
                    node.parent.parent.color = "R"
                    self.right_rotate(node.parent.parent)
            else:
                uncle = node.parent.parent.left
                if uncle.color == "R":
                    node.parent.color = "B"
                    uncle.color = "B"
                    node.parent.parent.color = "R"
                    node = node.parent.parent
                else:
                    if node == node.parent.left:
                        node = node.parent
                        self.right_rotate(node)
                    node.parent.color = "B"
                    node.parent.parent.color = "R"
                    self.left_rotate(node.parent.parent)
        self.root.color = "B"

    def left_rotate(self, x):
        y = x.right
        x.right = y.left
        if y.left != self.NIL_LEAF:
            y.left.parent = x
        y.parent = x.parent
        if x.parent is None:
            self.root = y
        elif x == x.parent.left:
            x.parent.left = y
        else:
            x.parent.right = y
        y.left = x
        x.parent = y

    def right_rotate(self, x):
        y = x.left
        x.left = y.right
        if y.right != self.NIL_LEAF:
            y.right.parent = x
        y.parent = x.parent
        if x.parent is None:
            self.root = y
        elif x == x.parent.right:
            x.parent.right = y
        else:
            x.parent.left = y
        y.right = x
        x.parent = y

    def delete(self, data):
        self.delete_node_helper(self.root, data)

    def delete_node_helper(self, node, key):
        z = self.NIL_LEAF
        while node != self.NIL_LEAF:
            if node.data == key:
                z = node
            if node.data <= key:
                node = node.right
            else:
                node = node.left

        if z == self.NIL_LEAF:
            print("Silinecek eleman ağaçta bulunamadı.")
            return

        y = z
        y_original_color = y.color
        if z.left == self.NIL_LEAF:
            x = z.right
            self.rb_transplant(z, z.right)
        elif z.right == self.NIL_LEAF:
            x = z.left
            self.rb_transplant(z, z.left)
        else:
            y = self.minimum(z.right)
            y_original_color = y.color
            x = y.right
            if y.parent == z:
                x.parent = y
            else:
                self.rb_transplant(y, y.right)
                y.right = z.right
                y.right.parent = y
            self.rb_transplant(z, y)
            y.left = z.left
            y.left.parent = y
            y.color = z.color
        if y_original_color == "B":
            self.fix_delete(x)

    def rb_transplant(self, u, v):
        if u.parent == None:
            self.root = v
        elif u == u.parent.left:
            u.parent.left = v
        else:
            u.parent.right = v
        v.parent = u.parent

    def fix_delete(self, x):
        while x != self.root and x.color == "B":
            if x == x.parent.left:
                s = x.parent.right
                if s.color == "R":
                    s.color = "B"
                    x.parent.color = "R"
                    self.left_rotate(x.parent)
                    s = x.parent.right
                if s.left.color == "B" and s.right.color == "B":
                    s.color = "R"
                    x = x.parent
                else:
                    if s.right.color == "B":
                        s.left.color = "B"
                        s.color = "R"
                        self.right_rotate(s)
                        s = x.parent.right
                    s.color = x.parent.color
                    x.parent.color = "B"
                    s.right.color = "B"
                    self.left_rotate(x.parent)
                    x = self.root
            else:
                s = x.parent.left
                if s.color == "R":
                    s.color = "B"
                    x.parent.color = "R"
                    self.right_rotate(x.parent)
                    s = x.parent.left
                if s.left.color == "B" and s.right.color == "B":
                    s.color = "R"
                    x = x.parent
                else:
                    if s.left.color == "B":
                        s.right.color = "B"
                        s.color = "R"
                        self.left_rotate(s)
                        s = x.parent.left
                    s.color = x.parent.color
                    x.parent.color = "B"
                    s.left.color = "B"
                    self.right_rotate(x.parent)
                    x = self.root
        x.color = "B"

    def minimum(self, node):
        while node.left != self.NIL_LEAF:
            node = node.left
        return node

    def print_tree(self, node, indent="", last=True):
        if node != self.NIL_LEAF:
            print(indent, end="")
            if last:
                print("R----", end="")
                indent += "     "
            else:
                print("L----", end="")
                indent += "|    "
            color = "K" if node.color == "R" else "S"
            print(f"{node.data}({color})")
            self.print_tree(node.left, indent, False)
            self.print_tree(node.right, indent, True)

def main():
    tree = RedBlackTree()
    print("Metehan Ayhan\nNot: Her düğümün altında aynı hizada yazan R L harfleri o düğümün sağda mı solda mı konumlandığını gösteriyor.\nYanında yazan S K harfleri ise kırmızı ya da siyah renkte olduğunu bildiriyor.")
    while True:
        print("\nKırmızı-Siyah Ağaç İşlemleri")
        print("1. Ekle")
        print("2. Sil")
        print("3. Çıkış")
        secim = input("Seçiminizi yapın (1/2/3): ")
        if secim == '1':
            data = int(input("Eklenecek sayıyı girin: "))
            tree.insert(data)
            tree.print_tree(tree.root)
        elif secim == '2':
            data = int(input("Silinecek sayıyı girin: "))
            tree.delete(data)
            tree.print_tree(tree.root)
        elif secim == '3':
            print("Programdan çıkılıyor...")
            break
        else:
            print("Geçersiz seçim! Lütfen tekrar deneyin.")

if __name__ == "__main__":
    main()
