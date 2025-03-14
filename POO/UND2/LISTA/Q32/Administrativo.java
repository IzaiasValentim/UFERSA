package POO.UND2.LISTA.Q32;

public class Administrativo extends Assistente {
	private boolean turno; // Dia = true, Noite =false;
	private double adicionalNoturno;

	public Administrativo(String nome, double salario, String matricula, boolean turno, double adicionalNoturno) {
		super(nome, salario, matricula);
		this.turno = turno;
		this.adicionalNoturno = adicionalNoturno;
	}

	public double getAdicionalNoturno() {
		return adicionalNoturno;
	}

	public void setAdicionalNoturno(double adicionalNoturno) {
		if (this.turno == false) {
			this.adicionalNoturno = adicionalNoturno;
		}
	}

	public String getTurno() {
		if (this.turno) {
			return "Diurno";
		} else {
			return "Noturno";
		}
	}

	public void setTurno(boolean turno) {
		this.turno = turno;
	}

	@Override
	public double ganhoAnual() {
		double ganhoMensal = this.getSalario() * 12 + this.getAdicionalNoturno() * 12;
		double decimoTerceiro = (this.getSalario() / 12 * 12);

		return ganhoMensal + decimoTerceiro;
	}

	@Override
	public String toString() {
		return "Tipo: Assistente Administrativo; \nTurno: " + this.getTurno() + "\nAdicional noturno: "
				+ this.getAdicionalNoturno() + ""
				+ super.toString();
	}
}
