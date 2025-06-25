package Q4;

// Classe Cliente para demonstrar a cadeia de decoração
class ClienteDecorator {
    public static void main(String[] args) {
        // Pedido simples
        Pedido pedidoBase = new PedidoSimples();
        System.out.println("Descrição: " + pedidoBase.getDescricao());
        System.out.println("Custo Total: R$" + pedidoBase.calcularCusto()); // Saída: R$50.0

        System.out.println("--------------------");

        // Pedido com embalagem para presente
        Pedido pedidoComPresente = new EmbalagemParaPresenteDecorador(new PedidoSimples());
        System.out.println("Descrição: " + pedidoComPresente.getDescricao());
        System.out.println("Custo Total: R$" + pedidoComPresente.calcularCusto()); // Saída: R$60.0

        System.out.println("--------------------");

        // Pedido com frete expresso e seguro
        Pedido pedidoComFreteESeguro = new FreteExpressoDecorador(new SeguroDecorador(new PedidoSimples()));
        System.out.println("Descrição: " + pedidoComFreteESeguro.getDescricao());
        System.out.println("Custo Total: R$" + pedidoComFreteESeguro.calcularCusto()); // Saída: R$90.0 (50 + 15 + 25)

        System.out.println("--------------------");

        // Pedido com todas as funcionalidades (cadeia de decoração completa)
        Pedido pedidoCompleto = new EmbalagemParaPresenteDecorador(
                new FreteExpressoDecorador(
                        new SeguroDecorador(
                                new PedidoSimples()
                        )));
        System.out.println("Descrição: " + pedidoCompleto.getDescricao());
        System.out.println("Custo Total: R$" + pedidoCompleto.calcularCusto()); // Saída: R$100.0 (50 + 15 + 25 + 10)
    }
}
