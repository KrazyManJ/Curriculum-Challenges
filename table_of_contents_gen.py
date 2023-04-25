from os import path, listdir, pardir
from pathlib import Path

def table_of_contents():
    content = ""
    for dir in [p for p in listdir() if path.isdir(p) and not p.startswith(".")]:
        content += f"- [{dir}]({dir})\n"
        for file in [path.join(dir,p) for p in listdir(dir) if p.endswith(".c")]:
            linklabel = " ".join(
                [a.capitalize() for a in Path(file).stem.replace("_"," ").split(" ")]
            )
            content += f"    - [{linklabel}]({file})\n"
    return content
        
        
print(table_of_contents())
    
    