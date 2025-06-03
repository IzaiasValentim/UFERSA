public class Aluno extends Pessoa {
    private String matricula;
    private String curso;

    // Construtor
    public Aluno(String nome, int idade, String matricula, String curso) {
        super(nome, idade);
        this.matricula = matricula;
        this.curso = curso;
    }

    public String getMatricula() {
        return matricula;
    }

    public String getCurso() {
        return curso;
    }

    public void setMatricula(String matricula) {
        this.matricula = matricula;
    }

    public void setCurso(String curso) {
        this.curso = curso;
    }

    @Override
    public void exibirInformacoes() {
        super.exibirInformacoes();
        System.out.println("  Matrícula: " + matricula + ", Curso: " + curso + ".");
    }

    public void fazerMatricula(String novoCurso) {
        this.setCurso(novoCurso);
        System.out.println(getNome() + " matriculou-se no curso de " + novoCurso + ".");
    }
}