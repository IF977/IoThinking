require 'test_helper'

class AmbientesControllerTest < ActionController::TestCase
  setup do
    @ambiente = ambientes(:one)
  end

  test "should get index" do
    get :index
    assert_response :success
    assert_not_nil assigns(:ambientes)
  end

  test "should get new" do
    get :new
    assert_response :success
  end

  test "should create ambiente" do
    assert_difference('Ambiente.count') do
      post :create, ambiente: { name: @ambiente.name }
    end

    assert_redirected_to ambiente_path(assigns(:ambiente))
  end

  test "should show ambiente" do
    get :show, id: @ambiente
    assert_response :success
  end

  test "should get edit" do
    get :edit, id: @ambiente
    assert_response :success
  end

  test "should update ambiente" do
    patch :update, id: @ambiente, ambiente: { name: @ambiente.name }
    assert_redirected_to ambiente_path(assigns(:ambiente))
  end

  test "should destroy ambiente" do
    assert_difference('Ambiente.count', -1) do
      delete :destroy, id: @ambiente
    end

    assert_redirected_to ambientes_path
  end
end
