# ⏰ Jam Digital Arduino dengan RTC DS1307 & TM1637 Display + 3 Tombol Fungsional

> Sebuah jam digital minimalis nyaman dilihat siang maupun malam 🌗

---

## 🔧 Apa Ini?

Proyek ini adalah **jam digital berbasis Arduino Uno** yang menggunakan:

- **RTC DS1307**: menjaga waktu tetap akurat dan berjalan meski Arduino mati
- **TM1637 4-Digit Display**: menampilkan waktu dengan format HH:MM
- **3 Tombol**:
  - 1 tombol untuk atur **jam**
  - 1 tombol untuk atur **menit**
  - 1 tombol untuk atur **tingkat kecerahan layar**

---

## 🎯 Kenapa Pakai 3 Tombol?

### 1️⃣ Tombol Atur Jam

> Karena kita tahu, kadang jam butuh disesuaikan saat dibawa ke **zona waktu berbeda**. Bayangkan kamu bawa alat ini dari Jakarta ke Papua — tinggal tekan tombol, jam langsung beres.

### 2️⃣ Tombol Atur Menit

> Sama seperti jam, menit pun kadang perlu disesuaikan. Terutama kalau RTC pernah dilepas baterainya atau hanya ingin sinkron dengan jam resmi lokal.

### 3️⃣ Tombol Atur Kecerahan

> TM1637 secara default **sangat terang**. Di ruangan gelap, itu bisa bikin silau. Karena itu, aku tambahkan **kontrol brightness** dari 0 (paling redup) sampai 7 (paling terang), agar anda bisa menyesuaikan dengan kondisi pencahayaan — **nyaman untuk mata**.

---

## 🛠️ Perangkat Keras yang Digunakan

| Komponen          | Jumlah | Catatan                            |
| ----------------- | ------ | ---------------------------------- |
| Arduino Uno R3    | 1      | Board utama                        |
| RTC DS1307 Module | 1      | Modul waktu real-time + baterai    |
| TM1637 4-digit    | 1      | Layar LED 7-segment 4 digit        |
| Push Button       | 3      | Jam, Menit, dan Brightness control |
| Kabel jumper      | ~10    | Bebas warna                        |
| Breadboard        | 1      | Optional                           |
| Baterai CR2032    | 1      | Untuk backup RTC                   |

---

## 🧠 Fitur Utama

- ✅ Tampilkan waktu real-time format HH:MM
- ✅ Pengaturan jam dan menit langsung dari tombol
- ✅ Kecerahan layar yang bisa disesuaikan dengan satu tombol
- ✅ Waktu tetap tersimpan walau Arduino mati (karena RTC + baterai)
- ✅ Tidak perlu koneksi komputer hanya untuk setting waktu!

---

## ⚡ Wiring (Perkabelan)

### 🕐 RTC DS1307 → Arduino Uno

- SDA → A4
- SCL → A5
- VCC → 5V
- GND → GND

### 🔢 TM1637 → Arduino Uno

- CLK → D8
- DIO → D9
- VCC → 5V
- GND → GND

### 🔘 Tombol Tekan (semua ke GND & pin digital)

- BTN_JAM → D2
- BTN_MENIT → D3
- BTN_BRIGHT → D4

> Semua tombol menggunakan `INPUT_PULLUP`, jadi tidak butuh resistor eksternal.

---

## 📸 Dokumentasi Tambahan

![Wiring Diagram](docs/arduino%20clock.png)

---

## 🚀 Cara Menggunakan

1. Upload file `jam_digital.ino` ke Arduino Uno
2. Pastikan RTC memiliki baterai (CR2032)
3. Cek display, waktu akan tampil otomatis
4. Tekan tombol:
   - ⬆️ D2 → tambah jam
   - ⬆️ D3 → tambah menit
   - ⬆️ D4 → atur brightness (berputar dari 0–7)

---

## ✨ Roadmap (Ide Pengembangan)

- ⏳ Tambahkan alarm sederhana
- 🔔 Bunyi buzzer saat jam berganti

---

## 🙌 Kontribusi

Punya ide tambahan? Silakan buat **issue** atau **pull request**.

---
