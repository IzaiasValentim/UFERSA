public class Professor extends Pessoa {
    private double salario;
    private String disciplina;

    public Professor(String nome, int idade, double salario, String disciplina) {
        super(nome, idade);
        this.salario = salario;
        this.disciplina = disciplina;
    }

    public double getSalario() {
        return salario;
    }

    public String getDisciplina() {
        return disciplina;
    }

    public void setSalario(double salario) {
        this.salario = salario;
    }

    public void setDisciplina(String disciplina) {
        this.disciplina = disciplina;
    }

    @Override
    public void exibirInformacoes() {
        super.exibirInformacoes();
        System.out.println("  Salário: R$" + String.format("%.2f", salario) + ", Disciplina: " + disciplina + ".");
    }

    public void lecionar() {
        System.out.println(getNome() + " está lecionando a disciplina de " + disciplina + ".");
    }
}