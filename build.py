# -*- coding: UTF-8 -*-
import os
import sys

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

def getLang(lang):
    if lang == 'sh':    lang = 'shell'
    elif lang == 'py':  lang = 'python'
    elif lang == 'cpp': lang = 'c++'
    elif lang == 'hpp': lang = 'c++'
    return lang

def writeFile(text):
    f = open("codebook.md",'w+')
    f.write(text)
    f.close()

def buildMD(Filelist):
    text="# CodeBook by 櫛風\n"
    text+="[toc]\n"
    for file in Filelist:
        try:
            lang = getLang(file[file.find('.')+1:])
            filename = file[:file.find('.')]
            prog = "### " + filename + "\n"
            prog += "```" + lang + "\n"
            f = open(home+"/"+file,'r')
            print("    [file]["+lang+"]"+file)
            prog += f.read()
            f.close()
            prog += "```\n"
            text += prog
        except:
            home = file
            text += "## " + home[2:] + "\n"
            print("[dir]"+home[2:])
    writeFile(text)

print()
print("=============================================")
print("歡迎使用櫛風的CodeBook產生器")
print("=============================================")
Filelist = getFileist()
buildMD(Filelist)
print("=============================================")
print("done.\n")

if len(sys.argv)>1 and sys.argv[1]=='open':
        os.system("open codebook.md")
