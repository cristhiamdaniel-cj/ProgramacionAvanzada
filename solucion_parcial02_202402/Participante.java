package solucion_parcial02_202402;

import java.io.Serializable;

public abstract class Participante implements Serializable {
    private static final long serialVersionUID = 1L;
    private String nombre;
    private String correo;

    public Participante(String nombre, String correo) {
        this.nombre = nombre;
        this.correo = correo;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public String getCorreo() {
        return correo;
    }

    public void setCorreo(String correo) {
        this.correo = correo;
    }
}
