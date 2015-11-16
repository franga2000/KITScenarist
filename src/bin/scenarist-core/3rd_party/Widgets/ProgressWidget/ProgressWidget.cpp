#include "ProgressWidget.h"

#include <QApplication>
#include <QGridLayout>
#include <QLabel>
#include <QMovie>
#include <QProgressBar>


ProgressWidget::ProgressWidget(QWidget* _parent, bool _followToHeadWidget) :
	QLightBoxWidget(_parent, _followToHeadWidget)
{
	m_title = new QLabel("Title");
	m_title->setStyleSheet("font-size: 20pt; font-weight: 500; background-color: transparent; color: white; border: none; margin: 20px 0px 0px 12px;");

	QLabel* progress = new QLabel;
	progress->setStyleSheet("background-color: transparent; color: white; border: none;");
	QMovie* progressMovie = new QMovie(":/Interface/UI/loader.gif");
	progress->setMovie(progressMovie);
	progressMovie->start();

	m_description = new QLabel("Description.");
	m_description->setStyleSheet("background-color: transparent; color: white; border: none; margin: 0px 0px 0px 12px;");
#ifndef MOBILE_OS
	m_description->setFixedWidth(500);
#endif
	m_description->setWordWrap(true);

	QGridLayout* layout = new QGridLayout;
	layout->setRowStretch(0, 1);
	layout->setColumnStretch(0, 5);
	layout->addWidget(progress, 1, 1, 2, 1, Qt::AlignCenter);
	layout->addWidget(m_title, 1, 2, Qt::AlignLeft);
	layout->setColumnStretch(3, 4);
	layout->addWidget(m_description, 2, 2, Qt::AlignLeft | Qt::AlignTop);
	layout->setRowMinimumHeight(2, 50);

	layout->setRowStretch(3, 1);
	setLayout(layout);
}

void ProgressWidget::showProgress(const QString& _title, const QString& _description)
{
	m_title->setText(_title);
	m_description->setText(_description);

	show();
}

void ProgressWidget::setProgressText(const QString& _title, const QString& _description)
{
	if (!_title.isEmpty()) {
		m_title->setText(_title);
	}
	if (!_description.isEmpty()) {
		m_description->setText(_description);
	}
}

void ProgressWidget::finish()
{
	close();
	QApplication::alert(parentWidget());
}