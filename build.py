# -*- coding: UTF-8 -*-
import os

text="# CodeBook by 櫛風\n"
text+="[toc]\n"

Filelist = []
for home,dirs,files in os.walk("."):
    files = [f for f in files if not f[0] == '.']
    dirs[:] = [d for d in dirs if not d[0] == '.']
    if home == ".":
        continue
    Filelist.append(home)
    for filename in files:
        Filelist.append(filename)

for file in Filelist:
    try:
        lang = file[file.find('.')+1:]
        if lang == 'sh':
            lang += 'ell'
        elif lang == 'py':
            lang += 'thon'
        elif lang == 'hpp':
            lang = 'cpp'
        prog = "### " + file[:file.find('.')] + "\n"
        prog += "```" + lang + "\n"
        f = open(home+"/"+file,'r')
        prog += f.read()
        f.close()
        prog += "```\n"
        text += prog
    except:
        home = file
        text += "## "+file[2:]+"\n"

f = open("codebook.md",'w+')
f.write(text)
f.close()
