#include "Camera.h"

Camera::Camera() :
	position(0.0f, 0.0f, -5.0f),
	target(0.0f, 0.0f, 0.0f),
	up(0.0f, 1.0f, 0.0f),
	pitch(0.0f),
	yaw(0.0f),
	movementSpeed(5.0f),
	mouseSensitivity(0.005f)
{

	GLFWmonitor* primaryMonitor = glfwGetPrimaryMonitor();
	videoMode = glfwGetVideoMode(primaryMonitor);
	
	float aspectRatio = videoMode->width / videoMode->height;
        	aspectRatio *= 0.9;

	projectionMatrix = DirectX::XMMatrixPerspectiveFovLH(DirectX::XMConvertToRadians(45.0f),
		aspectRatio, 1.0f, 200.0f);


	UpdateViewMatrix();

}

static double lastMouseX = 0.0;
static double lastMouseY = 0.0;

void Camera::Update(float deltaTime, GLFWwindow* window)
{
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);


	double mouseX, mouseY;

	glfwGetCursorPos(window, &mouseX, &mouseY);


	DirectX::XMFLOAT3 forward;

	forward.x = cosf(pitch) * sinf(yaw);
	forward.y = sinf(pitch);
	forward.z = cosf(pitch) * cosf(yaw);

	DirectX::XMVECTOR forwardVec = DirectX::XMLoadFloat3(&forward);
	forwardVec = DirectX::XMVector3Normalize(forwardVec);

	DirectX::XMVECTOR upVec = DirectX::XMLoadFloat3(&up);
	DirectX::XMVECTOR rightVec = DirectX::XMVector3Cross(forwardVec, upVec);
	rightVec = DirectX::XMVector3Normalize(rightVec);


	DirectX::XMFLOAT3 right;
	DirectX::XMStoreFloat3(&right, rightVec);

	float cameraSpeed = movementSpeed * deltaTime;

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {

		position.x += forward.x * cameraSpeed;
		position.y += forward.y * cameraSpeed;
		position.z += forward.z * cameraSpeed;

		std::cout << "W presses" << std::endl;
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
		position.x -= forward.x * cameraSpeed;
		position.y -= forward.y * cameraSpeed;
		position.z -= forward.z * cameraSpeed;
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
		position.x += right.x * cameraSpeed;
		position.y += right.y * cameraSpeed;
		position.z += right.z * cameraSpeed;
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
		
		position.x -= right.x * cameraSpeed;
		position.y -= right.y * cameraSpeed;
		position.z -= right.z * cameraSpeed;
	}

	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {

		position.y += cameraSpeed ;
	}

	if (glfwGetKey(window, GLFW_KEY_LEFT_ALT) == GLFW_PRESS) {

		position.y -= cameraSpeed;
	}


	float xOffset = (float)(mouseX - lastMouseX);
	float yOffset = (float)(mouseY - lastMouseY);

	lastMouseX = mouseX;
	lastMouseY = mouseY;

	yaw += (float)xOffset * mouseSensitivity;
	pitch += (float)yOffset * mouseSensitivity;

	target = DirectX::XMFLOAT3(position.x + forward.x, position.y + forward.y, position.z + forward.z);

	UpdateViewMatrix();
}


void Camera::UpdateViewMatrix()
{


	viewMatrix = DirectX::XMMatrixLookAtLH(

		DirectX::XMLoadFloat3(&position),   // Camera position
		DirectX::XMLoadFloat3(&target),     // Target we're looking at
		DirectX::XMLoadFloat3(&up)          // Up direction\

	);

}



DirectX::XMMATRIX Camera::GetViewMatrix() const {

	 return DirectX::XMMatrixTranspose(viewMatrix);
}

// Get the projection matrix (used in rendering pipeline)
DirectX::XMMATRIX Camera::GetProjectionMatrix() const {
	return DirectX::XMMatrixTranspose(projectionMatrix);
}

// Get the camera's position in world space
DirectX::XMFLOAT3 Camera::GetPosition() const {

	return position;
}
