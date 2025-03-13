package POO.UND2.LISTA.Q17;

public class Main {
	public static void main(String[] args) {
		Agenda agenda = new Agenda();
		EntradaEmAgenda compromissoUm = new EntradaEmAgenda("Comemorar", 20, 12, 9, 2025);
		EntradaEmAgenda compromissoDois = new EntradaEmAgenda("Prova POO", 14, 18, 3, 2025);

		agenda.adicionarCompromisso(compromissoUm);
		agenda.adicionarCompromisso(compromissoDois);

		agenda.listaDia(12, 9, 2025);
		agenda.listaDia(1, 3, 2025);
	}
}
