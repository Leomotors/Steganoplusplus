# Steganoplusplus

My Implementation of Steganography

## Idea

[Inspired by BornToDev's Video](https://www.youtube.com/watch?v=2HeyTSBqIzY)

## Example

### Original Picture vs Encrypted

<img src="./example/Chino.png" width="300px">
<img src="./example/Output.png" width="300px">

### sha256sum

<img src="./example/sha256sum.png" width="600px">

### Encrypt and Decrypt

<img src="./example/example.png" width="600px">

### You can even Encrypt A File!

<img src="./example/srcmain.png" width="600px">

## 🌿 Dependencies

- OpenCV 4.5.3

## ⚙️ Installation

```
git clone https://github.com/Leomotors/Steganoplusplus
cd Steganoplusplus
mkdir build && cd build
cmake .. && make
sudo make install
```

## 📚 Usage

`Sgpp "File Name" Message` to encrypt

You can also use `Sgpp "File Name" --stdin` to get input from stdin (Like Pipe)

`Sgpp "File Name"` to decrypt
