def clasificar(lista):
    if isinstance(lista,list):
        return c_aux()
    else:
        "error"

def c_aux(lista):
    if lista==[]:
        return []
    elif lista[0][0].lower()=="M":
        print("yey")
        return c_aux(lista[1:])
    else:
        return c_aux(lista[1:])