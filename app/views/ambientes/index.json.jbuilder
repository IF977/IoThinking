json.array!(@ambientes) do |ambiente|
  json.extract! ambiente, :id, :name
  json.url ambiente_url(ambiente, format: :json)
end
