package POO.UND2.LISTA.Q32;

public class Tecnico extends Assistente {
	private double bonusSalarial;

	public Tecnico(String nome, double salario, String matricula, double bonusSalarial) {
		super(nome, salario, matricula);
		this.bonusSalarial = bonusSalarial;
	}

	public double getBonusSalarial() {
		return bonusSalarial;
	}

	public void setBonusSalarial(float bonusSalarial) {
		this.bonusSalarial = bonusSalarial;
	}

	@Override
	public double ganhoAnual() {
		// Se o bonus for 0.0 não irá influenciar os cálculos.
		double ganhoMensal = this.getSalario() * 12 + this.bonusSalarial * 12;
		double decimoTerceiro = (this.getSalario() / 12 * 12) + (this.getBonusSalarial() / 12 * 12);

		return ganhoMensal + decimoTerceiro;
	}

	@Override
	public String toString() {
		return "Tipo: Assistente Técnico;\nBônus salarial: " + this.getBonusSalarial() + "" + super.toString();
	}
}
