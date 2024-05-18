package solucion_parcial02_202402;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileReader;
import java.io.ObjectInputStream;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.List;

import java.io.*;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.List;

import java.io.*;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        try {
            GestorEventos gestor = new GestorEventos();

            SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd");

            // Crear eventos
            Evento evento1 = new EventoAcademico("Conferencia Java", sdf.parse("2024-05-17"), 200, "Ingeniería");
            Evento evento2 = new EventoExterno("Taller Python", sdf.parse("2024-06-01"), 50, "Python Software Foundation", 100);

            // Agregar eventos
            gestor.agregarEvento(evento1);
            gestor.agregarEvento(evento2);

            // Crear participantes
            Participante p1 = new ParticipanteInterno("Juan Perez", "juan@example.com", "Ingeniería");
            Participante p2 = new ParticipanteExterno("Ana Gomez", "ana@example.com", "Empresa XYZ");

            // Registrar participantes en eventos
            gestor.agregarParticipante("Conferencia Java", p1);
            gestor.agregarParticipante("Taller Python", p2);

            // Mostrar detalles de los eventos
            System.out.println("Evento Académico: " + evento1.getNombre());
            System.out.println("Evento Externo: " + evento2.getNombre() + " patrocinado por " + ((EventoExterno) evento2).getPatrocinador());

            // Guardar eventos en archivo de texto
            gestor.guardarEventosEnArchivo("eventos.txt");

            // Serializar eventos
            gestor.serializarEventos("eventos.ser");

            // Deserializar eventos
            gestor.deserializarEventos("eventos.ser");

            // Generar reporte de eventos
            gestor.reporteEventos("reporte_eventos.txt");

            // Validar contenido de los archivos
            System.out.println("\nContenido de eventos.txt:");
            try (BufferedReader br = new BufferedReader(new FileReader("eventos.txt"))) {
                String linea;
                while ((linea = br.readLine()) != null) {
                    System.out.println(linea);
                }
            }

            System.out.println("\nContenido de reporte_eventos.txt:");
            try (BufferedReader br = new BufferedReader(new FileReader("reporte_eventos.txt"))) {
                String linea;
                while ((linea = br.readLine()) != null) {
                    System.out.println(linea);
                }
            }

            System.out.println("\nDeserializando eventos.ser:");
            try (ObjectInputStream ois = new ObjectInputStream(new FileInputStream("eventos.ser"))) {
                @SuppressWarnings("unchecked")
                List<Evento> eventosDeserializados = (List<Evento>) ois.readObject();
                for (Evento e : eventosDeserializados) {
                    System.out.println(e);
                }
            }

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
