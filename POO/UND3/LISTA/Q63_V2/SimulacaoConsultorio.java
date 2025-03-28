package POO.UND3.LISTA.Q63_V2;

import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Random;

public class SimulacaoConsultorio {
	public static void main(String[] args) {
		final int totalConsultas = 20;
		final int tempoTotal = totalConsultas * 5;

		Random r = new Random();

		Queue<V2Paciente> filaComum = new LinkedList<>();
		PriorityQueue<V2Paciente> filaPrioritaria = new PriorityQueue<>();

		int tempoAtual = 0;
		int cadAtual = 0;
		int consultaAtual = 0;
		System.out.println("Iniciando o sistema: ");
		while (tempoAtual < tempoTotal) {
			System.out.printf("\nMinuto %d do horários de consultas:", tempoAtual);
			if (cadAtual < 20) {
				System.out.println("++ Realizando o cadastro de um novo paciente: ");
				// Cadastrando um paciente
				int idade = 10 + r.nextInt(80);
				int rg = 100000 + r.nextInt(900000);
				V2Paciente paciente = new V2Paciente(rg, idade);
				if (paciente.getIdade() > 60) {
					filaPrioritaria.add(paciente);
				} else {
					filaComum.add(paciente);
				}
				System.out.println("-Cadastrado um novo paciente: " + paciente);
				cadAtual++;
			}
			if (tempoAtual % 5 == 0 && consultaAtual < 20) {
				if (!filaPrioritaria.isEmpty()) {
					System.out.println("~! Atendimento prioritário: " + filaPrioritaria.peek());
					filaPrioritaria.poll();
				} else if (!filaComum.isEmpty()) {
					System.out.println("~ Atendimento comum: " + filaComum.peek());
					filaComum.poll();
				}
				consultaAtual++;
			}
			System.out.printf("\nFim do Minuto %d do horários de consultas.\n", tempoAtual);
			tempoAtual++;
		}
	}
}
