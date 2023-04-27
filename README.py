from os import path, listdir, pardir
from pathlib import Path

def table_of_contents():
    content = ""
    for dir in [p for p in listdir() if path.isdir(p) and not p.startswith(".")]:
        content += f"- [{dir}]({dir})\n"
        for file in [dir+"/"+p for p in listdir(dir) if p.endswith(".c")]:
            pdf = dir+"/"+Path(file).stem+".pdf"
            label = " ".join([a.capitalize() for a in Path(file).stem.replace("_"," ").split(" ")])
            content += f"    - **{label}** [[Code]({file})] [[Description]({pdf})]\n"
    return content
        
        
open("README.md","w",encoding="UTF-8").write(f"""
# Curriculum Challenges

## Table Of Contents

{table_of_contents()}
""".strip())
    
    