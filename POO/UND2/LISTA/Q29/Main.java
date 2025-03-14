package POO.UND2.LISTA.Q29;

public class Main {
	public static void main(String[] args) {

		// Instanciamento do evento com delegação:
		DataHora dhEvUm = new DataHora(13, 3, 2025, 13, 55);
		EventoDelegacao eventoDel = new EventoDelegacao("Aula POO", dhEvUm);
		System.out.println(eventoDel);

		// Instanciamento do evento por herança:
		EventoHeranca eventoHe = new EventoHeranca(13, 3, 2025, 13, 55, "Aula POO");
		System.out.println(eventoHe);

	}
}
