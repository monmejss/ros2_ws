import rclpy
from rclpy.node import Node
from std_msgs.msg import Float32MultiArray

class CortezaParietalNode(Node):
    def __init__(self):
        # Inicializa el nodo 
        super().__init__('corteza_parietal_node')

        self.pub_posicion = self.create_publisher(Float32MultiArray, '/parietal/posicion', 10)
        self.pub_percepcion = self.create_publisher(Float32MultiArray, '/parietal/percepcion', 10)

        # Suscriptor: escucha las coordenadas
        self.sub_dorsal = self.create_subscription(
            Float32MultiArray,
            '/occipital/corriente_dorsal', 
            self.callback_posicion,          
            10
        )

        # Suscriptor: escucha las dimensiones y puntos de contacto desde la corriente ventral
        self.sub_ventral = self.create_subscription(
            Float32MultiArray,
            '/occipital/corriente_ventral',  
            self.callback_percepcion,        
            10
        )

        # Mensaje de inicio
        self.get_logger().info('Corteza Parietal: escuchando datos de la corteza occipital')

    def callback_posicion(self, msg):
        self.pub_posicion.publish(msg)
        self.get_logger().info(f'Subnodo Posicion: Coordenadas recibidas y reenviadas: {msg.data}')

    def callback_percepcion(self, msg):
        self.pub_percepcion.publish(msg)
        self.get_logger().info(f'Subnodo Percepcion: Percepcion recibida y reenviada: {msg.data}')


def main(args=None):
    rclpy.init(args=args)
    node = CortezaParietalNode()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass

    node.destroy_node()
    rclpy.shutdown()
