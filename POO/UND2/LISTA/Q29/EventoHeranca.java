package POO.UND2.LISTA.Q29;

public class EventoHeranca extends DataHora {
	private String nomeDoEvento;

	public EventoHeranca(int dia, int mes, int ano, int horas, int minutos, String nomeDoEvento) {
		super(dia, mes, ano, horas, minutos);
		this.nomeDoEvento = nomeDoEvento;
	}

	public String getNomeDoEvento() {
		return nomeDoEvento;
	}

	public void setNomeDoEvento(String nomeDoEvento) {
		this.nomeDoEvento = nomeDoEvento;
	}

	@Override
	public String toString() {
		return String.format("*heranca* Nome do evento: %s - ", this.getNomeDoEvento()) + super.toString();
	}
}
