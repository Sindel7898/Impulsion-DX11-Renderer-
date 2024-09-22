#pragma once
#include <DirectXMath.h>
#include <iostream>
#include <GLFW/glfw3.h>  // GLFW for handling input

class Camera {

public:

    static Camera& GetInstance() {

        static Camera CameraInstance;
        return CameraInstance;
    }


    // Update camera matrices (to be called every frame)
    void Update(float deltaTime, GLFWwindow* window);

    // Getters for the view and projection matrices
    DirectX::XMMATRIX GetViewMatrix() const;
    DirectX::XMMATRIX GetProjectionMatrix() const;

    // Get the position of the camera
    DirectX::XMFLOAT3 GetPosition() const;

private:


    Camera(const Camera&) = delete;
    Camera& operator=(const Camera&) = delete;


    Camera();

    // Camera properties
    DirectX::XMFLOAT3 position;
    DirectX::XMFLOAT3 target;
    DirectX::XMFLOAT3 up;

    // Camera angles for rotation
    float pitch;
    float yaw;

    // Movement speed and sensitivity for mouse input
    float movementSpeed;
    float mouseSensitivity;

    // Camera matrices
    DirectX::XMMATRIX viewMatrix;
    DirectX::XMMATRIX projectionMatrix;

    const GLFWvidmode* videoMode;
    // Update the camera's view matrix based on position and angles
    void UpdateViewMatrix();
};
