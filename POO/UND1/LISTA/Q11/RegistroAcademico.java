package POO.UND1.LISTA.Q11;

public class RegistroAcademico {
	// Atributo estático.
	public static int numeroDeMatriculas;

	private String nome;
	private String matricula;
	private int codCurso;
	private double percentualDeCobranca;

	// Substituí o método inicializaRegistroAcademico() pelo construtor.
	public RegistroAcademico(String n, int cod, double p) {
		nome = n;
		codCurso = cod;
		percentualDeCobranca = p;
		++numeroDeMatriculas;
		matricula = codCurso + "M" + numeroDeMatriculas;
	}

	public double calculaMensalidade() {
		return 100 * codCurso * percentualDeCobranca;
	}

	public void imprime() {
		System.out.println(
				"\nAluno(a): " + nome + "\nMatrícula: " + matricula + "\nCódigo do Curso: " + codCurso
						+ "\nMensalidade: "
						+ calculaMensalidade());
	}

	public static void infoRegistros() {
		System.out.println("Total de matrículas: " + numeroDeMatriculas);
	}
}
