
public class Sistema {
	public static void main(String[] args) {
		// Instânciamento de dois alunos
		Aluno tainar = new Aluno(4455, "Tainar", 10.0D, 7.0D, 7.0D);
		Aluno alguem = new Aluno(4456, "Alguem", 4.0D, 4.0D, 7.0D);
		
		// Impressão da situação dos alunos.
		tainar.situacaoDoAluno();
		alguem.situacaoDoAluno();
	}
}
