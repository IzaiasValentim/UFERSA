package Q8;

// Cliente para demonstrar a hierarquia e a exibição recursiva
class Main {
    public static void main(String[] args) {
        // Criando formas simples (folhas)
        ElementoGrafico circulo1 = new Circulo("Círculo A", 10, 20, 5.0);
        ElementoGrafico quadrado1 = new Quadrado("Quadrado B", 30, 40, 10.0);
        ElementoGrafico circulo2 = new Circulo("Círculo C", 50, 60, 7.0);

        // Criando um grupo principal
        GrupoDeFormas grupoPrincipal = new GrupoDeFormas("Desenho Principal");
        grupoPrincipal.adicionar(circulo1);
        grupoPrincipal.adicionar(quadrado1);

        // Criando um subgrupo
        GrupoDeFormas subGrupo = new GrupoDeFormas("Sub-Desenho");
        subGrupo.adicionar(circulo2);
        subGrupo.adicionar(new Quadrado("Quadrado D", 70, 80, 12.0));

        // Adicionando o subgrupo ao grupo principal
        grupoPrincipal.adicionar(subGrupo);

        // Exibindo a hierarquia completa
        System.out.println("\n--- Exibindo o Desenho Completo ---");
        grupoPrincipal.exibir();

        // Movendo o grupo principal (e, consequentemente, tudo dentro dele)
        System.out.println("\n--- Movendo o Desenho Principal ---");
        grupoPrincipal.mover(5, 5);

        System.out.println("\n--- Exibindo o Desenho Completo (após mover) ---");
        grupoPrincipal.exibir();
    }
}
