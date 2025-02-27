package POO.UND1.LISTA.Q9;

public class NumeroComplexo {
	private double parteReal;
	private double parteImaginaria;

	public NumeroComplexo(double real, double imaginaria) {
		parteReal = real;
		parteImaginaria = imaginaria;
	}

	public NumeroComplexo(double real) {
		parteReal = real;
		parteImaginaria = 0.0D;
	}

	public NumeroComplexo() {
		parteReal = 0.0D;
		parteImaginaria = 0.0D;
	}

	public void setParteReal(double parteReal) {
		this.parteReal = parteReal;
	}

	public void setParteImaginaria(double parteImaginaria) {
		this.parteImaginaria = parteImaginaria;
	}

	@Override
	public String toString() {
		return "(" + parteReal + " + " + parteImaginaria + "i)";
	}
}
