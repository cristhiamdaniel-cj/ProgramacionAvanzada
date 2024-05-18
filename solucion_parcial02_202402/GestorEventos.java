package solucion_parcial02_202402;

import java.io.*;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;

public class GestorEventos {
    private List<Evento> eventos;

    public GestorEventos() {
        eventos = new ArrayList<>();
    }

    public void agregarEvento(Evento evento) throws Exception {
        for (Evento e : eventos) {
            if (e.equals(evento)) {
                throw new Exception("El evento con nombre " + evento.getNombre() + " ya existe.");
            }
        }
        eventos.add(evento);
    }

    public Evento buscarEventoPorNombre(String nombre) {
        for (Evento e : eventos) {
            if (e.getNombre().equals(nombre)) {
                return e;
            }
        }
        return null;
    }

    public List<Evento> buscarEventosPorFecha(Date fecha) {
        List<Evento> resultado = new ArrayList<>();
        for (Evento e : eventos) {
            if (e.getFecha().equals(fecha)) {
                resultado.add(e);
            }
        }
        return resultado;
    }

    public List<Evento> buscarEventosPorFechas(Date fechaInicial, Date fechaFinal) {
        List<Evento> resultado = new ArrayList<>();
        for (Evento e : eventos) {
            if (!e.getFecha().before(fechaInicial) && !e.getFecha().after(fechaFinal)) {
                resultado.add(e);
            }
        }
        return resultado;
    }

    public void agregarParticipante(String nombreEvento, Participante participante) throws Exception {
        Evento evento = buscarEventoPorNombre(nombreEvento);
        if (evento == null) {
            throw new Exception("El evento no existe.");
        }
        for (Evento e : eventos) {
            if (e.getFecha().equals(evento.getFecha()) && e.getParticipantes().contains(participante)) {
                throw new Exception("El participante ya está registrado en otro evento en la misma fecha.");
            }
        }
        evento.registrarParticipante(participante);
    }

    public void guardarEventosEnArchivo(String nombreArchivo) throws IOException {
        try (BufferedWriter bw = new BufferedWriter(new FileWriter(nombreArchivo))) {
            for (Evento evento : eventos) {
                bw.write(evento.toString());
                bw.newLine();
            }
        }
    }

    public void cargarEventosDeArchivo(String nombreArchivo) throws IOException {
        try (BufferedReader br = new BufferedReader(new FileReader(nombreArchivo))) {
            String linea;
            while ((linea = br.readLine()) != null) {
                if (linea.startsWith("EventoExterno{")) {
                    String[] partes = linea.replace("EventoExterno{", "").replace("}", "").split(",");
                    String nombre = partes[0].split("=")[1].trim();
                    String ubicacion = partes[1].split("=")[1].trim();
                    int capacidad = Integer.parseInt(partes[2].split("=")[1].trim());
                    String fecha = partes[3].split("=")[1].trim();
                    String patrocinador = partes[4].split("=")[1].trim();
                    int tarifaPorParticipante = Integer.parseInt(partes[5].split("=")[1].trim());
                    eventos.add(new EventoExterno(nombre, new SimpleDateFormat("yyyy-MM-dd").parse(fecha), capacidad, patrocinador, tarifaPorParticipante));
                } else if (linea.startsWith("EventoAcademico{")) {
                    String[] partes = linea.replace("EventoAcademico{", "").replace("}", "").split(",");
                    String nombre = partes[0].split("=")[1].trim();
                    String ubicacion = partes[1].split("=")[1].trim();
                    int capacidad = Integer.parseInt(partes[2].split("=")[1].trim());
                    String fecha = partes[3].split("=")[1].trim();
                    String facultad = partes[4].split("=")[1].trim();
                    eventos.add(new EventoAcademico(nombre, new SimpleDateFormat("yyyy-MM-dd").parse(fecha), capacidad, facultad));
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public void serializarEventos(String nombreArchivo) throws IOException {
        try (ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(nombreArchivo))) {
            oos.writeObject(eventos);
        }
    }

    public void deserializarEventos(String nombreArchivo) throws IOException, ClassNotFoundException {
        try (ObjectInputStream ois = new ObjectInputStream(new FileInputStream(nombreArchivo))) {
            eventos = (List<Evento>) ois.readObject();
        }
    }

    public void reporteEventos(String nombreArchivo) throws IOException {
        try (BufferedWriter bw = new BufferedWriter(new FileWriter(nombreArchivo))) {
            for (Evento evento : eventos) {
                bw.write("Evento: " + evento.getNombre());
                bw.newLine();
                bw.write("Fecha: " + evento.getFecha());
                bw.newLine();
                bw.write("Capacidad: " + evento.getCapacidad() + " participantes");
                bw.newLine();
                bw.write("Tipo: " + (evento instanceof EventoAcademico ? "Académico" : "Externo"));
                bw.newLine();
                bw.write("Participantes:");
                bw.newLine();
                for (Participante p : evento.getParticipantes()) {
                    bw.write(p.toString());
                    bw.newLine();
                }
                bw.newLine();
            }
        }
    }
}
