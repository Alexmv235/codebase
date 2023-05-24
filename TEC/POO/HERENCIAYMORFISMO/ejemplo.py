class TransporteVehicle:
    def __init__(self,company_name,fee, public_transport):
        if isinstance(company_name,str) and isinstance(fee,int) and isinstance(public_transport,bool):
            self.company_name= company_name
            self.fee=fee
            self.public_transport=public_transport
    def drive(self):
        print('manejando')
    def metodo_random():
        print('hola')

class Bus(TransporteVehicle):
    def __init__(self, company_name, fee, public_transport,seats,route):
        TransporteVehicle.__init__(self,company_name, fee, public_transport)
        self.seats=seats
        self.route=route
    def drive(self):
        print('manejando desde el bus')
    def metodo_random(self):
        print('adios')
    def goterminal(self):
        print('hacia la terminal')


class Taxi(TransporteVehicle):
    def __init__(self, company_name, fee, public_transport,province):
        TransporteVehicle.__init__(self,company_name, fee, public_transport)
        self.province=province
    def drive(self):
        print('manejando desde el taxi')
    def awnser_call(self):
        print('contestando llamada')

