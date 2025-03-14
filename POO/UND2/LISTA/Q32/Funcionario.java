package POO.UND2.LISTA.Q32;

public class Funcionario {
	private String nome;
	private double salario;

	public Funcionario(String nome, double salario) {
		this.nome = nome;
		this.salario = salario;
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public double getSalario() {
		return salario;
	}

	public void setSalario(double salario) {
		this.salario = salario;
	}

	public void aumentarSalario(double valorDeAumento) {
		salario += valorDeAumento;
	}

	public double ganhoAnual() {

		double ganhoMensal = salario * 12;

		// Considerando que trabalhou os 12 meses.
		double decimoTerceiro = salario / 12 * 12;

		return ganhoMensal + decimoTerceiro;
	}

	@Override
	public String toString() {
		return "\nNome:" + nome + "\nSalario atual: " + salario + "\nGanho total anual: " + ganhoAnual();
	}
}
