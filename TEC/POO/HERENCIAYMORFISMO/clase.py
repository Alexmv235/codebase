class CE1101():
    def __init__(self,nombre,email,telefono):
        self.nombre=nombre
        self.telefono=telefono
        self.email=email

class Estudiante(CE1101):
    def __init__(self, nombre, email, telefono, carne, materias, notas):
        CE1101.__init__(self, nombre, email, telefono)
        self.carne=carne
        self.materias=materias
        self.notas=notas

class Profesor(CE1101):
    def __init__(self, nombre, email, telefono,cedula,cursos):
        CE1101.__init__(self,nombre, email, telefono)
        self.cedula=cedula
        self.cursos=cursos