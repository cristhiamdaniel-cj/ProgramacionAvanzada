package solucion_parcial02_202402;

import java.io.Serializable;

public class ParticipanteExterno extends Participante {
    private static final long serialVersionUID = 1L;
    private String entidad;

    public ParticipanteExterno(String nombre, String correo, String entidad) {
        super(nombre, correo);
        this.entidad = entidad;
    }

    public String getEntidad() {
        return entidad;
    }

    public void setEntidad(String entidad) {
        this.entidad = entidad;
    }

    @Override
    public String toString() {
        return super.toString() + " (" + entidad + ")";
    }
}
