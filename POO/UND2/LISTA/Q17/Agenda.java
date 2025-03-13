package POO.UND2.LISTA.Q17;

import java.util.ArrayList;

public class Agenda {
	// ArrayList de EntradaEmAgenda.
	ArrayList<EntradaEmAgenda> compromissos;

	// Construtor.
	public Agenda() {
		compromissos = new ArrayList<>();
	}

	// Adiciona um compromisso.
	public void adicionarCompromisso(EntradaEmAgenda comp) {
		compromissos.add(comp);

		System.out.println("Compromisso adicionado: ");
		System.out.println(comp);
		System.out.println();
	}

	// Lista todos os compromissos na data informada.
	public void listaDia(int d, int m, int a) {
		System.out.printf("Compromissos do dia: %d/%d/%d:\n", d, m, a);
		for (int c = 0; c < compromissos.size(); c++) {
			if (compromissos.get(c).ehNoDia(d, m, a)) {
				System.err.println(compromissos.get(c));
			}
		}
		System.out.println();
	}
}
