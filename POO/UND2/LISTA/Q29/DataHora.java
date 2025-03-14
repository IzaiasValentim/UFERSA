package POO.UND2.LISTA.Q29;

public class DataHora {
	private int dia;
	private int mes;
	private int ano;
	private int horas;
	private int minutos;

	public DataHora(int dia, int mes, int ano, int horas, int minutos) {
		this.dia = dia;
		this.mes = mes;
		this.ano = ano;
		this.horas = horas;
		this.minutos = minutos;
	}

	public int getDia() {
		return dia;
	}

	public void setDia(int dia) {
		this.dia = dia;
	}

	public int getMes() {
		return mes;
	}

	public void setMes(int mes) {
		this.mes = mes;
	}

	public int getAno() {
		return ano;
	}

	public void setAno(int ano) {
		this.ano = ano;
	}

	public int getHoras() {
		return horas;
	}

	public void setHoras(int horas) {
		this.horas = horas;
	}

	public int getMinutos() {
		return minutos;
	}

	public void setMinutos(int minutos) {
		this.minutos = minutos;
	}

	@Override
	public String toString() {
		return String.format("Data: %d/%d/%d, hora: %d:%d",
				this.getDia(), this.getMes(), this.getAno(), this.getHoras(), this.getMinutos());
	}

}
