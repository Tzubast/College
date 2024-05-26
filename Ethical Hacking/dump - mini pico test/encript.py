def caesar_cipher(text, shift):
    encrypted_text = ""
    for char in text:
        if char.isalpha():  # Cek apakah karakter adalah huruf
            shifted = ord(char) + shift
            if char.islower():
                if shifted > ord('z'):
                    shifted -= 26
                elif shifted < ord('a'):
                    shifted += 26
            elif char.isupper():
                if shifted > ord('Z'):
                    shifted -= 26
                elif shifted < ord('A'):
                    shifted += 26
            encrypted_text += chr(shifted)
        else:
            encrypted_text += char
    return encrypted_text

text = input("Masukkan teks yang ingin dienkripsi: ")
shift = int(input("Masukkan jumlah pergeseran: "))

encrypted_text = caesar_cipher(text, shift)
print("Teks terenkripsi:", encrypted_text)
