#include "Game.h"

bool updatable = false;

Game::Game() : window(VideoMode(800, 600), "OpenGL Cube")
{
	index = glGenLists(1);
	m_cubePoints[0] = MyVector3D(1.0f, 1.0f, -5.0f);
	m_cubePoints[1] = MyVector3D(-1.0f, 1.0f, -5.0f);
	m_cubePoints[2] = MyVector3D(-1.0f, -1.0f, -5.0f);
	m_cubePoints[3] = MyVector3D(1.0f, -1.0f, -5.0f);

	m_cubePoints[4] = MyVector3D(1.0f, 1.0f, -15.0f);
	m_cubePoints[5] = MyVector3D(-1.0f, 1.0f, -15.0f);
	m_cubePoints[6] = MyVector3D(-1.0f, -1.0f, -15.0f);
	m_cubePoints[7] = MyVector3D(1.0f, -1.0f, -15.0f);
}

Game::~Game(){}

void Game::run()
{

	initialize();

	Event event;

	while (isRunning){

		cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}

			//translate left
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				for (int i = 0; i < 8; i++)
				{
					m_cubePoints[i] = m_matrix.translate(0.1, 0.0)*m_cubePoints[i];
				}
			}
			//translate right
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				for (int i = 0; i < 8; i++)
				{
					m_cubePoints[i] = m_matrix.translate(-0.1, 0.0)*m_cubePoints[i];
				}
			}
			//translate up
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			{
				for (int i = 0; i < 8; i++)
				{
					m_cubePoints[i] = m_matrix.translate(0.0, -0.1)*m_cubePoints[i];
				}
			}
			//translate down
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				for (int i = 0; i < 8; i++)
				{
					m_cubePoints[i] = m_matrix.translate(0.0, 0.1)*m_cubePoints[i];
				}
			}
			//scale down
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				for (int i = 0; i < 8; i++)
				{
					m_cubePoints[i] = m_matrix.scale(90,90)*m_cubePoints[i];
				}
			}
			//scale up
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				for (int i = 0; i < 8; i++)
				{
					m_cubePoints[i] = m_matrix.scale(110, 110)*m_cubePoints[i];
				}
			}

			//rotate on y
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
			{
				for (int i = 0; i < 8; i++)
				{
					m_cubePoints[i] = m_matrix.rotationY(1)*m_cubePoints[i];
				}
			}
			//rotate on x
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
			{
				for (int i = 0; i < 8; i++)
				{
					m_cubePoints[i] = m_matrix.rotationX(1)*m_cubePoints[i];
				}
			}
			//rotate on z
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
			{
				for (int i = 0; i < 8; i++)
				{
					m_cubePoints[i] = m_matrix.rotationZ(1)*m_cubePoints[i];
				}
			}
			
		}
		update();
		initialize();
		draw();
	}

}

void Game::initialize()
{
	isRunning = true;

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);

	// glNewList(index, GL_COMPILE);
	// Creates a new Display List
	// Initalizes and Compiled to GPU
	// https://www.opengl.org/sdk/docs/man2/xhtml/glNewList.xml
	glNewList(index, GL_COMPILE);
	glBegin(GL_QUADS);
	{
		//Front Face
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(m_cubePoints[0].getX(), m_cubePoints[0].getY(), m_cubePoints[0].getZ()); //0
		glVertex3f(m_cubePoints[1].getX(), m_cubePoints[1].getY(), m_cubePoints[1].getZ()); //1
		glVertex3f(m_cubePoints[2].getX(), m_cubePoints[2].getY(), m_cubePoints[2].getZ()); //2
		glVertex3f(m_cubePoints[3].getX(), m_cubePoints[3].getY(), m_cubePoints[3].getZ()); //3

		////Back Face
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(m_cubePoints[4].getX(), m_cubePoints[4].getY(), m_cubePoints[4].getZ());  //4
		glVertex3f(m_cubePoints[5].getX(), m_cubePoints[5].getY(), m_cubePoints[5].getZ());  //5
		glVertex3f(m_cubePoints[6].getX(), m_cubePoints[6].getY(), m_cubePoints[6].getZ());  //6
		glVertex3f(m_cubePoints[7].getX(), m_cubePoints[7].getY(), m_cubePoints[7].getZ());  //7

		////right face		
		glColor3f(1.0f, 0.0f, 1.0f);
		glVertex3f(m_cubePoints[0].getX(), m_cubePoints[0].getY(), m_cubePoints[0].getZ());  //0
		glVertex3f(m_cubePoints[4].getX(), m_cubePoints[4].getY(), m_cubePoints[4].getZ());  //4
		glVertex3f(m_cubePoints[7].getX(), m_cubePoints[7].getY(), m_cubePoints[7].getZ());  //7
		glVertex3f(m_cubePoints[3].getX(), m_cubePoints[3].getY(), m_cubePoints[3].getZ());  //3

		////left face
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(m_cubePoints[1].getX(), m_cubePoints[1].getY(), m_cubePoints[1].getZ());  //1
		glVertex3f(m_cubePoints[5].getX(), m_cubePoints[5].getY(), m_cubePoints[5].getZ());  //5
		glVertex3f(m_cubePoints[6].getX(), m_cubePoints[6].getY(), m_cubePoints[6].getZ());  //6
		glVertex3f(m_cubePoints[2].getX(), m_cubePoints[2].getY(), m_cubePoints[2].getZ());  //2

		////top face
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex3f(m_cubePoints[4].getX(), m_cubePoints[4].getY(), m_cubePoints[4].getZ());  //4
		glVertex3f(m_cubePoints[5].getX(), m_cubePoints[5].getY(), m_cubePoints[5].getZ());  //5
		glVertex3f(m_cubePoints[1].getX(), m_cubePoints[1].getY(), m_cubePoints[1].getZ());  //1
		glVertex3f(m_cubePoints[0].getX(), m_cubePoints[0].getY(), m_cubePoints[0].getZ());  //0

		////bottom face
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(m_cubePoints[7].getX(), m_cubePoints[7].getY(), m_cubePoints[7].getZ());  //7
		glVertex3f(m_cubePoints[6].getX(), m_cubePoints[6].getY(), m_cubePoints[6].getZ());  //6
		glVertex3f(m_cubePoints[2].getX(), m_cubePoints[2].getY(), m_cubePoints[2].getZ());  //2
		glVertex3f(m_cubePoints[3].getX(), m_cubePoints[3].getY(), m_cubePoints[3].getZ());  //3

		//Complete the faces of the Cube

	}
	glEnd();
	glEndList();
}

void Game::update()
{
	elapsed = clock.getElapsedTime();

	if (elapsed.asSeconds() >= 1.0f)
	{
		clock.restart();

		if (!updatable)
		{
			updatable = true;
		}
		else
			updatable = false;
	}

	if (updatable)
	{
		//rotationAngle += 0.005f;

		if (rotationAngle > 360.0f)
		{
			rotationAngle -= 360.0f;
		}
	}
	
	cout << "Update up" << endl;
}

void Game::draw()
{
	cout << "Drawing" << endl;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	cout << "Drawing Cube " << endl;
	glLoadIdentity();
	glRotatef(rotationAngle, 0, 1, 0); // Rotates the camera on Y Axis

	glCallList(1);

	window.display();

}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}

