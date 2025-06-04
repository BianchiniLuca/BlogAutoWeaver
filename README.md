# BlogAutoWeaver

This project is a **semi-automatic static blog generator** written in C++/Qt.  
It uses a simple template system to produce static HTML pages from plain text files.

The goal is to create static blog sites that are easy to manage and publish.

---

## 🚀 Features

✅ Multi-file input:  
Reads all `.wvr` files in the selected input folder.

✅ Template-based generation:  
Randomly selects one HTML template (from the `/templates` folder) for each `.wvr` file.

✅ Simple content insertion:  
Each `.wvr` file’s content is inserted where `{{content}}` appears in the chosen template.

---

## 🏗 Project Structure

/BlogAutoWeaver/  
README.md  
LICENSE  
main.cpp  
mainwindow.cpp/h/ui  
weavercore.cpp/h  
templates/  
template1.html, ...

---

## 🔧 How to Use

1. **Prepare your input folder**  
   Place one or more `.wvr` files containing your blog content (plain text) in the input directory.

2. **Run the application**  
   Select the template, input, and output directories as requested by the UI. Click “Generate”.

3. **Find your output**  
   - HTML files are generated in your chosen output folder.
   - Each `.wvr` file produces a `.html` file with the same base name.

4. **Deploy**  
   Upload the generated `.html` files to your static web host or server.

---

## 📄 License

This project is licensed under the MIT License.

© Luca Bianchini, 2025

---

## 🌐 Links

- Author website: [lucabianchini.eu](https://lucabianchini.eu)