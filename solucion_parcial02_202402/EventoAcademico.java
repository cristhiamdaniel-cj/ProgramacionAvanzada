package solucion_parcial02_202402;

import java.util.Date;

public class EventoAcademico extends Evento {
    private static final long serialVersionUID = 1L;
    public static final int TARIFA_FIJA = 100;
    private String facultad;

    public EventoAcademico(String nombre, Date fecha, int capacidad, String facultad) {
        super(nombre, fecha, capacidad);
        this.facultad = facultad;
    }

    @Override
    public int calcularCosto() {
        int costo = 0;
        for (Participante participante : getParticipantes()) {
            if (participante instanceof ParticipanteInterno) {
                ParticipanteInterno interno = (ParticipanteInterno) participante;
                if (!interno.getFacultad().equalsIgnoreCase(facultad)) {
                    costo += TARIFA_FIJA;
                }
            } else {
                costo += TARIFA_FIJA;
            }
        }
        return costo;
    }
}
