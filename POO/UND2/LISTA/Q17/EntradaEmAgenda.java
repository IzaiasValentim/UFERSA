package POO.UND2.LISTA.Q17;

public class EntradaEmAgenda {

	//Dados necessários.
	private String assunto;
	private int dia;
	private int mes;
	private int ano;
	private int hora;

	// Construtor.
	public EntradaEmAgenda(String assunto,int hora, int dia, int mes, int ano) {
		this.assunto = assunto;
		this.hora = hora;
		this.dia = dia;
		this.mes = mes;
		this.ano = ano;
	}

	// toString.
	@Override
	public String toString() {
		return String.format("%s - Data: %d/%d/%d às %d horas.", assunto, dia, mes, ano, hora);
	}

	// Verifica se esta ocorrência é no dia passado.
	public Boolean ehNoDia(int d, int m, int a) {
		return dia == d && mes == m && ano == a;
	}
}
