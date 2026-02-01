# M5StampS3A + ESP-IDF 最小サンプル

M5StampS3A（ESP32-S3）向けの ESP-IDF 最小サンプルです。UARTログに「Hello」メッセージとシステム情報を出力し、1秒ごとに空きヒープを表示します。

## できること
- シリアルモニタに起動ログとシステム情報を出力
- 1秒ごとに動作中ログを出力

## 必要な環境
- ESP-IDF v5.x
- Python 3.8 以上
- USBケーブル（M5StampS3A と PC を接続）

## 環境セットアップ

### 1. ESP-IDF のインストール
公式ドキュメントの手順に従ってインストールしてください。
- https://docs.espressif.com/projects/esp-idf/ja/latest/esp32s3/get-started/

### 2. ESP-IDF の環境読み込み

インストールした ESP-IDF を有効化します。

```bash
. $HOME/esp/esp-idf/export.sh
```

## ビルドと書き込み

### 1. ターゲット指定

```bash
idf.py set-target esp32s3
```

### 2. ビルド

```bash
idf.py build
```

### 3. 書き込み + モニタ

M5StampS3A を USB で接続し、ポートを確認してから実行します。

```bash
idf.py -p /dev/ttyACM0 flash monitor
```

- Windows なら `COMx` を指定してください（例: `-p COM5`）。
- macOS なら `/dev/tty.usbmodem*` がよく使われます。

終了するには `Ctrl+]` を押します。

## 期待される出力例

```
I (0) m5stamps3a: Hello from M5StampS3A!
I (0) m5stamps3a: ESP-IDF version: v5.x
I (0) m5stamps3a: Chip revision: 0
I (0) m5stamps3a: Flash size: 8388608 bytes
I (1000) m5stamps3a: Running... free heap: 3xxxxx bytes
```

## 次のステップ

- GPIO で LED を点滅させたい場合は `main/main.c` に GPIO 初期化とトグル処理を追加してください。
- Wi-Fi や I2C などの機能は ESP-IDF のサンプルから取り込むと理解しやすいです。
