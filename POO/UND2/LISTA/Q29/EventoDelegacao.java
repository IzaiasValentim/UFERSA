package POO.UND2.LISTA.Q29;

public class EventoDelegacao {
	private String nomeEvento;
	private DataHora dataEHorario;

	public EventoDelegacao(String nomeEvento, DataHora dataEHorario) {
		this.nomeEvento = nomeEvento;
		this.dataEHorario = dataEHorario;
	}

	public String getNomeEvento() {
		return nomeEvento;
	}

	public void setNomeEvento(String nomeEvento) {
		this.nomeEvento = nomeEvento;
	}

	public DataHora getDataEHorario() {
		return dataEHorario;
	}

	public void setDataEHorario(DataHora dataEHorario) {
		this.dataEHorario = dataEHorario;
	}

	@Override
	public String toString() {
		return String.format("*delegação* Nome do evento: %s - ", this.getNomeEvento()) + this.getDataEHorario().toString();
	}
}
