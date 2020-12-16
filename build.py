# -*- coding: UTF-8 -*-
import os

def buildMD(Filelist):
    text="# CodeBook by 櫛風\n"
    text+="[toc]\n"
    for file in Filelist:
        try:
            lang = file[file.find('.')+1:]
            if lang == 'sh':
                lang = 'shell'
            elif lang == 'py':
                lang = 'python'
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
    print("done.")

def getFileist():
    Filelist = []
    for home,dirs,files in os.walk("."):
        files = [f for f in files if not f[0] == '.']
        dirs[:] = [d for d in dirs if not d[0] == '.']
        if home == ".":continue
        Filelist.append(home)
        for filename in files:
            Filelist.append(filename)
    return Filelist

Filelist = getFileist()
buildMD(Filelist)
# os.system("open codebook.md")
