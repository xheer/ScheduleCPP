#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);

  QWidget *window = new QWidget;
  window->setWindowTitle("Hello, World!");

  QPushButton *button = new QPushButton("Click me to print 'Hello, World!'");

  QVBoxLayout *layout = new QVBoxLayout;
  layout->addWidget(button);
  window->setLayout(layout);

  QObject::connect(button, &QPushButton::clicked, []() {
    std::cout << "Hello, World!" << std::endl;
  });

  window->show();

  return app.exec();
}