# Tracker Harga Bitcoin Pakai ESP8266 & OLED Display 🚀

**Mau tahu harga Bitcoin sekarang tanpa buka HP? Yuk, bikin tracker keren ini pakai ESP8266 dan OLED display!**

---

## ✨ Tentang Proyek ini

Proyek ini adalah membuat alat sederhana untuk memantau harga Bitcoin real-time. Alat ini menggunakan ESP8266 sebagai otak utama, OLED untuk menampilkan data, dan CoinDesk API sebagai sumber harga Bitcoin. Cocok buat yang suka ngulik Arduino dan IoT!

Kelebihan alat ini:

- **Portabel banget**: Bisa dicolok ke power bank.
- **Langsung kelihatan**: Harga Bitcoin langsung di layar, nggak perlu buka aplikasi.

---

## 🎉 Fitur-Fitur 😎

- ✨ **Harga Bitcoin Real-Time**: Pantau harga Bitcoin (USD) langsung dari API CoinDesk.
- 🔤 **Layar OLED**: Data ditampilkan di layar 128x64.
- 🛏️ **Koneksi Wi-Fi**: Langsung nyambung ke Wi-Fi kamu.
- ⏳ **Update Berkala**: Harga otomatis refresh tiap 60 detik (bisa diubah kalau kamu lagi nggak sabar).

---

## 🛠 Alat dan Bahan

- ESP8266 (kayak NodeMCU)
- OLED display 128x64 (SSD1306)
- Kabel jumper (warna-warni biar estetik ✨)
- Kabel USB + Power Bank/Adaptor (buat nyalain ESP8266)

---

## ⚙️ Cara Kerja

1. **Setup Wi-Fi**: ESP8266 akan nyambung ke Wi-Fi yang udah kamu set di kode.
2. **Fetch Data**: Ambil data harga Bitcoin terbaru dari API CoinDesk.
3. **Tampilkan di OLED**: Data yang diambil langsung ditampilkan di layar OLED dengan format yang mudah dibaca.
4. **Auto Refresh**: Harga di-update otomatis setiap 60 detik biar kamu nggak ketinggalan info.

---

## 🔌 Cara Pasang

1. **Install Library Dulu**:
   Buka Arduino IDE dan install library ini:
   - `ESP8266WiFi`
   - `WiFiClientSecure`
   - `ArduinoJson`
   - `Adafruit_GFX`
   - `Adafruit_SSD1306`
2. **Sambungin Kabel**:
   Hubungkan OLED ke ESP8266 kayak gini:
   - `VCC` ke 3.3V
   - `GND` ke GND
   - `SCL` ke D1
   - `SDA` ke D2
3. **Edit Kode Wi-Fi**:
   Di bagian kode, masukkan Wi-Fi kamu:
   ```cpp
   const char* ssid = "<Nama WiFi Kamu>";
   const char* password = "<Password WiFi Kamu>";
   ```
4. **Upload Kodenya**:
   Gunakan kabel USB untuk upload kode ke ESP8266.
5. **Power On!**:
   Nyalakan alat, dan tunggu layar OLED menampilkan harga Bitcoin.

---

## 🔦 Cara Pakai

- **Langkah Pertama**: Pastikan alat terhubung ke Wi-Fi dengan benar.
- **Otomatis**: Harga Bitcoin bakal langsung ditampilkan di layar.
- **Refresh Otomatis**: Tunggu 60 detik untuk pembaruan harga berikutnya.
- **Troubleshooting**: Kalau layar nggak menampilkan apa-apa, cek koneksi Wi-Fi atau periksa kabelnya.

---

## Contoh Output di OLED

**Tampilan Kece di OLED:**

```
Harga Bitcoin (USD):
$34,567.89
Jan 11, 2025 03:10
```

---

## 🕵️ Catatan Penting

- Pastikan Wi-Fi kamu stabil biar datanya nggak gagal diambil.
- Kalau koneksi SSL gagal, layar OLED akan kasih tahu errornya.
- Mau update interval lebih cepat atau lambat? Tinggal ubah `UPDATE_INTERVAL` di kode.

---

## 🌟 Pesan Penutup

"Bikin alat ini ibarat ngoprek sambil ngemil: gampang dan hasilnya bikin bangga!" Kalau kamu nemu bug, mau improve, share di sini! 😄

**Semoga saldo Bitcoin kamu cepet "to the moon"!** 🚀

---

## 📜 Lisensi

Proyek ini open-source dan tersedia di bawah [MIT License](LICENSE).
