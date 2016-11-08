#include "my_dialog.h"
#include "ui_my_dialog.h"
#include <cassert>
#include <boost/graph/adjacency_list.hpp>

//The construct below only compiles with C++14 and boost
auto f() noexcept
{
  boost::adjacency_list<> g;
  boost::add_vertex(g);
  return boost::num_vertices(g);
}

my_dialog::my_dialog(QWidget *parent) noexcept :
  QDialog(parent),
  ui(new Ui::my_dialog)
{
  //The construct below only compiles in C++14
  assert(0 == 000'000); //!OCLINT indeed it is a constant expression
  assert(f() == 1);
  ui->setupUi(this);
  connect(
    ui->pushButton,
    &QPushButton::clicked,
    this,
    &my_dialog::close
  );
}

my_dialog::~my_dialog() noexcept
{
  delete ui;
}
