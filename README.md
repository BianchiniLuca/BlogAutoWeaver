# BlogAutoWeaver

This project is a **semi-automatic static blog generator** written in C++/Qt.  
It combines structured input data, random template selection, and dynamic related-post generation to produce professional, varied HTML blog pages.

The goal is to create static blog sites that look human-made, avoid repetition, and are easy to manage and publish.

---

## 🚀 Features

✅ Multi-file input:  
Reads all `.txt` files in the selected folder, ignoring filenames and focusing on contents.

✅ Special markers:  
Uses markers like:
- `[[dir verdi]]` → defines the directory and page name (`/verdi/index.html`)
- `[[img image.jpg][alt description]]` → embeds images with alt text
- `[[choice "Option 1" "Option 2"]]` → randomly selects one of multiple variants

✅ Randomized templates:  
Chooses from 3–4 predefined HTML templates to vary layout and styling.

✅ Dynamic related articles:  
Builds a live internal list of all posts and shuffles related article cards, simulating WordPress-like behavior.

✅ Centralized asset management:  
Copies all images into a shared folder (`/assets/img/`) for easy maintenance and renaming.

---

## 🏗 Project Structure

/BlogAutoWeaver/
README.md
LICENSE
main.cpp
templates/
template1.html

---

## 🔧 How to Use

1. **Prepare your input folder**  
   Place one or more `.txt` files containing your blog content with the correct markers.

2. **Run the application**  
   The app reads all files, processes the content, randomizes where needed, and generates the output site.

3. **Find your output**  
   - Root index page(s): `/output/index.html`, `/output/index-2.html`, etc.
   - Per-post folders: `/output/verdi/index.html`, `/output/mozart/index.html`, etc.
   - Shared assets: `/output/assets/img/`

4. **Deploy**  
   Upload the `/output` folder to your static web host or server.

---

## 📄 License

This project is licensed under the MIT License.

© Luca Bianchini, 2025

---

## 🌐 Links

- Author website: [lucabianchini.eu](https://lucabianchini.eu)
