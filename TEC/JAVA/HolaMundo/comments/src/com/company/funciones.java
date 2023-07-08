package com.company;

public class funciones {
    
    /**
     * @param args
     * Clase main de com.company.funciones
     */
    public static void main(String[] args) {
        
        mostrarNombre("Juanito");
    }

    /**
     * @param name
     * Esta es una función privada que recibe el parametro name y devuelve
     * hola concatenado con name
     */
    private static void mostrarNombre(String name) {
        System.out.println("Hola"+name);
    }

    /**
     * @param name
     * Esta es una función publica que recibe el parametro name un devuelve 
     * hola concetando con name
     */
    public static void cualMiNombre(String name) {
        System.out.println("Hola "+name);
    }

}
