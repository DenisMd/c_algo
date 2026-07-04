## Настройка форматирования

1) установить clang-format
```
sudo apt install clang-format
```

2) выберите стиль. [примеры стилей и конфигурация](https://clang.llvm.org/docs/ClangFormatStyleOptions.html)
```bash
clang-format -style=google -dump-config > ~/.clang-format
```
ИЛИ можете использовать мой **из этой папки**, нужно его скопировать к себе в домашнюю директорию
```bash
cp ./.clang-format ~/.clang-format
```


3) опционально можете отредактировать файл ```~/.clang-format```

4) Откройте настройки VsCode ```ctrl+,```

5) в поиске в группе user напишите **c_cpp.formating** и выберите в списке **clang-format**
