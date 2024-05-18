package solucion_parcial02_202402;

import java.io.Serializable;

public class ParticipanteInterno extends Participante {
    private static final long serialVersionUID = 1L;
    private String facultad;

    public ParticipanteInterno(String nombre, String correo, String facultad) {
        super(nombre, correo);
        this.facultad = facultad;
    }

    public String getFacultad() {
        return facultad;
    }

    public void setFacultad(String facultad) {
        this.facultad = facultad;
    }

    @Override
    public String toString() {
        return super.toString() + " (" + facultad + ")";
    }
}

