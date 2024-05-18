package solucion_parcial02_202402;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;

public abstract class Evento implements Serializable {
    private static final long serialVersionUID = 1L;
    private String nombre;
    private Date fecha;
    private int capacidad;
    private List<Participante> participantes;

    public Evento(String nombre, Date fecha, int capacidad) {
        this.nombre = nombre;
        this.fecha = fecha;
        this.capacidad = capacidad;
        this.participantes = new ArrayList<>();
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public Date getFecha() {
        return fecha;
    }

    public void setFecha(Date fecha) {
        this.fecha = fecha;
    }

    public int getCapacidad() {
        return capacidad;
    }

    public void setCapacidad(int capacidad) {
        this.capacidad = capacidad;
    }

    public List<Participante> getParticipantes() {
        return participantes;
    }

    public void registrarParticipante(Participante participante) throws Exception {
        if (participantes.size() >= capacidad) {
            throw new Exception("El evento ya alcanzó su capacidad límite.");
        }
        if (participantes.contains(participante)) {
            throw new Exception("El participante con el correo " + participante.getCorreo() + " ya está registrado.");
        }
        if (this instanceof EventoAcademico && participante instanceof ParticipanteExterno) {
            throw new Exception("No se puede inscribir un participante externo en un evento académico.");
        }
        participantes.add(participante);
    }

    public abstract int calcularCosto();

    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (obj == null || getClass() != obj.getClass()) return false;
        Evento evento = (Evento) obj;
        return nombre.equals(evento.nombre);
    }
}
