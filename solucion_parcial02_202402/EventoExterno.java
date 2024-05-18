package solucion_parcial02_202402;

import java.util.Date;

public class EventoExterno extends Evento {
    private static final long serialVersionUID = 1L;
    private String patrocinador;
    private int tarifaPorParticipante;

    public EventoExterno(String nombre, Date fecha, int capacidad, String patrocinador, int tarifaPorParticipante) {
        super(nombre, fecha, capacidad);
        this.patrocinador = patrocinador;
        this.tarifaPorParticipante = tarifaPorParticipante;
    }

    public String getPatrocinador() {
        return patrocinador;
    }

    public void setPatrocinador(String patrocinador) {
        this.patrocinador = patrocinador;
    }

    public int getTarifaPorParticipante() {
        return tarifaPorParticipante;
    }

    public void setTarifaPorParticipante(int tarifaPorParticipante) {
        this.tarifaPorParticipante = tarifaPorParticipante;
    }

    @Override
    public int calcularCosto() {
        int costo = 0;
        for (Participante participante : getParticipantes()) {
            if (participante instanceof ParticipanteExterno) {
                ParticipanteExterno externo = (ParticipanteExterno) participante;
                if (externo.getEntidad().equalsIgnoreCase(patrocinador)) {
                    costo += tarifaPorParticipante * 0.5;
                } else {
                    costo += tarifaPorParticipante;
                }
            } else {
                costo += tarifaPorParticipante;
            }
        }
        return costo;
    }

    @Override
    public String toString() {
        return "EventoExterno{" +
                "nombre='" + getNombre() + '\'' +
                ", fecha=" + getFecha() +
                ", capacidad=" + getCapacidad() +
                ", patrocinador='" + patrocinador + '\'' +
                ", tarifaPorParticipante=" + tarifaPorParticipante +
                '}';
    }
}
