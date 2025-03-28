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
		for (EntradaEmAgenda E : compromissos) {
			if (E.ehNoDia(d, m, a)) {
				System.out.println(E);
			}
		}
		System.out.println();
	}
}
