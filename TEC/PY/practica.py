def clasificar(lista):
    if isinstance(lista,list):
        return c_aux(lista)
    else:
        "error"
        
def c_aux(lista):
    return [c_aux_f(lista),c_aux_50(lista),int(c_aux_prom(lista)/c_aux_cont(lista))]

def c_aux_f(lista):
    if lista==[]:
        return []
    elif lista[0][0]=="F":
        return [lista[0]]+c_aux_f(lista[1:])
    else:
        return c_aux_f(lista[1:])

def c_aux_50(lista):
    if lista==[]:
        return []
    elif int(lista[0][2:])>50:
        return [lista[0]]+c_aux_50(lista[1:])
    else:
        return c_aux_50(lista[1:])

def c_aux_prom(lista):
    if lista==[]:
        return 0
    else:
        return int(lista[0][2:])+c_aux_prom(lista[1:])
        
def c_aux_cont(lista):
    if lista==[]:
        return 0
    else:
        return 1+c_aux_cont(lista[1:])

print(clasificar(["M-43","F-23","F-48","F-31","M-65","M-18","M-48"]))
